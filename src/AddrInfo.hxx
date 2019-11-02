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

#ifndef SHATNET_ADDRINFO_HXX
#define SHATNET_ADDRINFO_HXX
#ifdef _WIN32

#include <WinSock2.h>
#include <ws2tcpip.h>
#else
#endif
struct AddrInfo {
    addrinfo Info;
};


#endif //SHATNET_ADDRINFO_HXX
