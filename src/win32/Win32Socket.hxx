// ShatNet - Open Source Networking Library for Games

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
// Created by Marcel Kulina on 02/11/2019.
// Copyright (c) 2019 Broken Bytes All rights reserved.
//

#ifndef SHATNET_WIN32SOCKET_HXX
#define SHATNET_WIN32SOCKET_HXX
#include <WinSock2.h>

#include "../Socket.hxx"


namespace ShatNet::Windows {
	class Win32Socket : public Socket {
	public:
		Win32Socket(AddrInfo addrinfo);
		void Send(AddrInfo addrinfo, char data[]) override;
		void Close() override;

	private:
		int _socket;
		addrinfo _addrInfo;

		void Bind() override;
		void StartRead() override;
	};
}

#endif //SHATNET_WIN32SOCKET_HXX
