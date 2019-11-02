#ifndef SHATNET_TYPES_SHATNET_DATAGRAM__HXX
#define SHATNET_TYPES_SHATNET_DATAGRAM__HXX

#include <vector>
#include <array>
#include "ShatNetDefines.hxx"
#include "Socket.hxx"

namespace ShatNet::Types
{
	//                              |                   Meta Data 10 Bytes                |     Content      |
	// The Byte order is as follows |1 Byte Channel Id|7 Bytes Message Id|2 Bytes Msg Type|Buffer size - meta|
	class Datagram
	{
	public:
		enum Channel
		{
			Reliable,
			Unreliable,
			Sequenced
		};


		Datagram(std::vector<Socket> receivers,
			Channel channel,
			std::array<char, SOCKET_BUFFER_SIZE> data);

	 	[[nodiscard]] std::vector<Socket> Receivers() const;
		[[nodiscard]] std::array<char, SOCKET_BUFFER_SIZE> Data() const;

	private:
		Channel _channel;
		std::array<char, SOCKET_BUFFER_SIZE> _data;
		std::vector<Socket> _receivers;	
	};
}

#endif
