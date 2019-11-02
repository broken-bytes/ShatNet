// ShatNet - Open Source Networking Library for Games
//
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies
// or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// Created by Marcel Kulina on 02/11/2019.
// Copyright (c) 2019 Broken Bytes All rights reserved.
//


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
