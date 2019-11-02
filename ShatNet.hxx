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


#ifndef SHATNET_SHATNET_HXX
#define SHATNET_SHATNET_HXX
#include <cstdint>
#include <string>

namespace ShatNet {
	class Peer;
}

int main();


void Initialize();
void Uninitialize();
int Connect(std::string ip, uint16_t port);
int Host(uint16_t port);
int Send(ShatNet::Peer client, char data[]);
#endif
