from scapy.all import *

while(1):
	br = "ff:ff:ff:ff:ff:ff"
	dot11 = Dot11(addr1=br, addr2 = str(RandMAC()), addr3=str(RandMAC()))
	dot22 = Dot11(addr1=br, addr2 = str(RandMAC()), addr3=str(RandMAC()))
	dot33 = Dot11(addr1=br, addr2 = str(RandMAC()), addr3=str(RandMAC()))

	beacon1= Dot11Beacon(cap="ESS+privacy")
	beacon2= Dot11Beacon(cap="ESS", timestamp=1)
	beacon3= Dot11Beacon()

	essid1 = Dot11Elt(ID="SSID", info="floodingm")
	essid2 = Dot11Elt(ID="SSID", info="pythonflo")
	essid3 = Dot11Elt(ID="SSID", info="thirdmis")

	sendp(RadioTap(), dot11, beacon1, essid1, iface="wlan0", loop=0)
	sendp(RadioTap(), dot22, beacon2, essid2, iface="wlan0", loop=0)
	sendp(RadioTap(), dot33, beacon3, essid3, iface="wlan0", loop=0)
