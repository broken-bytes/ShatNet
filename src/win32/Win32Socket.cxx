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

#include <WinSock2.h>
#include <ws2tcpip.h>
#include "Win32Socket.hxx"
#include "../ShatNetDefines.hxx"
#include "../AddrInfo.hxx"


namespace ShatNet
{
	Windows::Win32Socket::Win32Socket(AddrInfo addrinfo)
	{
		_socket = socket(addrinfo.Info.ai_family, SOCK_DGRAM, 0);
		if (_socket == INVALID_SOCKET ||_socket == SOCKET_ERROR)
		{
			return;
		}
		_addrInfo = addrinfo.Info;
		Bind();
		StartRead();
	}

	void Windows::Win32Socket::Send(AddrInfo addrinfo, char data[])
	{
		int result = sendto(_socket,
			data,
			SOCKET_BUFFER_SIZE,
			0,
			reinterpret_cast<SOCKADDR *>(& addrinfo.Info),
			sizeof (addrinfo)
		);
	}

	void Windows::Win32Socket::Bind()
	{
		bind(_socket,
			reinterpret_cast<SOCKADDR*>(&_addrInfo),
			sizeof(_addrInfo)
		);
	}

	void Windows::Win32Socket::StartRead()
	{
		char buffer[SOCKET_BUFFER_SIZE];
		while (1)
		{
			SOCKADDR_IN remote;
			int remoteSize = sizeof(remote);
			int result = recvfrom(_socket,
				buffer,
				SOCKET_BUFFER_SIZE,
				0,
				reinterpret_cast<sockaddr*>(&remote),
				&remoteSize
			);

			if (result == SOCKET_ERROR)
			{
			}
			else
			{
				buffer[SOCKET_BUFFER_SIZE - 1] = '\0';
			}
		}
	}
}
