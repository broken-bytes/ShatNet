#include <thread>
#include <mutex>
#include "DatagramQueue.hxx"
#include "Datagram.hxx"
#include "Socket.hxx"


namespace ShatNet
{
	DatagramQueue::DatagramQueue(Socket sender)
	{
		_socket = std::make_shared<Socket>(sender);
		_active = true;
		_worker = std::thread(&ShatNet::DatagramQueue::Queue, this);
	}

	void DatagramQueue::Clear()
	{
		std::scoped_lock lock(_queueMutex);
		_queue.clear();
	}

	void DatagramQueue::Pop()
	{
		std::scoped_lock lock(_queueMutex);
		_queue.erase(_queue.end());
	}

	void DatagramQueue::Push(Types::Datagram datagram)
	{
		std::scoped_lock lock(_queueMutex);
		_queue.push_back(datagram);
	}

	void DatagramQueue::Remove(Types::Datagram datagram)
	{
		std::scoped_lock lock(_queueMutex);
	}


	void DatagramQueue::Queue()
	{
		while(_active)
		{
			std::scoped_lock lock(_queueMutex);
			for (int x = 0; x < _queue.size(); x++)
			{
				auto datagram = _queue[x];
				auto receivers = datagram.Receivers();
				for (auto receiver : datagram.Receivers())
				{
					_socket->Send(receiver, datagram);
				}
				_queue.erase(_queue.begin() + x);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(DATAGRAM_QUEUE_DELAY_MS));
		}
	}
}
