#include "Datagram.hxx"
#include <iostream>

namespace ShatNet::Types
{
	Datagram::Datagram(std::vector<Socket> receivers,
		Channel channel,
		std::array<char, 1024> data)
	{
		_receivers = std::move(receivers);
		_channel = channel;
		_data = data;
	}

	[[nodiscard]] std::array<char, 1024> Datagram::Data() const
	{
		return _data;
	}

	[[nodiscard]] std::vector<Socket> Datagram::Receivers() const
	{
		return _receivers;
	}



}
