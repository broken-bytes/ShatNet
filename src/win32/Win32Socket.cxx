// ShatNet

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
