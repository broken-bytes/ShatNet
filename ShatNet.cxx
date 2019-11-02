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




