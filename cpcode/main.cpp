#include <iostream>
#include <unistd.h>
#include <tins/tins.h>

using namespace std;
using namespace Tins;

Dot11Beacon makebeacon(std::string ssid, std::string fmac);

Dot11Beacon makebeacon(std::string ssid, std::string fmac)
{
	Dot11Beacon beacon;
	beacon.addr1(Dot11::BROADCAST);
	beacon.addr2(fmac);
	beacon.addr3(beacon.addr2());
	beacon.ssid(ssid);
	beacon.ds_parameter_set(8);
	beacon.supported_rates({ 1.0f, 5.5f, 11.0f });
	beacon.rsn_information(RSNInformation::wpa2_psk());
	return beacon;
}

int main(int argc, char *argv[])
{
    RadioTap radio[5];
    PacketSender sender;
    NetworkInterface interface("wlan0");
    char fmac[18]="00:07:89:00:00:00";

    radio[0].inner_pdu(makebeacon("wifiisflood!1",fmac));
    radio[1].inner_pdu(makebeacon("networkhomework?2",fmac+1));
    radio[2].inner_pdu(makebeacon("dangerouswifi3",fmac+2));
    radio[3].inner_pdu(makebeacon("connectme4",fmac+3));
    radio[4].inner_pdu(makebeacon("goodman5",fmac+4));

    while(true)
    {
	for (int i = 0; i<5; i++)
	{
		sender.send(radio[i], interface);
	}
	usleep(100000);
    }
}
