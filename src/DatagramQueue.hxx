#ifndef SHATNET_SHATNET_DATAGRAM_QUEUE_HXX
#define SHATNET_SHATNET_DATAGRAM_QUEUE_HXX
#include <WinSock2.h>
#include <vector>
#include <thread>
#include <mutex>

namespace ShatNet
{
	class Socket;

	// Forward declarations -------------
	namespace Types {
		class Datagram;
	}



	class DatagramQueue
	{
	public:
		DatagramQueue(Socket sender);
		void Clear();
		void Push(Types::Datagram);
		void Pop();
		void Remove(Types::Datagram);

	private:
		std::shared_ptr<Socket> _socket;
		std::vector<Types::Datagram> _queue;
		std::thread _worker;
		std::mutex _queueMutex;
		bool _active;

		void Queue();
	};
}
#endif
