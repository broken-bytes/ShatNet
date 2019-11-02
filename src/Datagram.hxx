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
