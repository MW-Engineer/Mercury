#include "Channel.h"

Channel::Channel(): address(0), outputValue(0), checksum(0)
{
}
Channel::Channel(uint32 newAddress): address(newAddress), outputValue(0), checksum(0)
{
}

Channel::~Channel()
{

}

