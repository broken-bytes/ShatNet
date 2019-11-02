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

#include "ShatNet.hxx"
#include "src/Socket.hxx"
#include <iostream>
#include "src/DatagramQueue.hxx"
#include "src/Datagram.hxx"
#include "src/Peer.hxx"

int main()
{
	Initialize();
	auto socket = ShatNet::Socket(2651);
	auto queue = new ShatNet::DatagramQueue(socket);
	auto receiver = ShatNet::Socket(62678, "192.168.0.202", ShatNet::Socket::IPv4);
	std::vector<ShatNet::Socket> receivers;
	receivers.reserve(2);
	receivers.push_back(receiver);
	std::array<char, SOCKET_BUFFER_SIZE> data;
	for(int x = 0; x < SOCKET_BUFFER_SIZE; x++)
	{
		data[x] = 'D';
	}
	while(true) {
		queue->Push(ShatNet::Types::Datagram(receivers, ShatNet::Types::Datagram::Reliable, data));
	}
	getchar();
	return 0;
}

void Initialize()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
	}

}

void Uninitialize()
{
	WSACleanup();
}

int Connect(std::string ip, uint16_t port)
{
	
}

int Send(ShatNet::Peer client, char data[])
{
	
}




