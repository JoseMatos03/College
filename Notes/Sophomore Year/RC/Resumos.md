## Chapter 1

$$
\text{Packet Transmission Delay} = \frac{L}{R}
$$

$L \rightarrow$ Length (bits)
$R \rightarrow$ Rate (bits/sec)

### Network Core

**Forwarding (switching)**:
- _local_ action, move arriving packets from router's input link to appropriate router output link
**Routing**:
- _global_ action, determine source-destination paths take by packets
- routing algorithms
![[Screenshot 2024-06-03 at 14.04.31.png]]
---

**Packet-Switching (queuing)**:
![[Screenshot 2024-06-03 at 14.06.11.png]]
Occurs when work arrives faster than it can be serviced.
Packets can be loss if router buffer overflows.

**Circuit-Switching**:
![[Screenshot 2024-06-03 at 14.08.57.png]]
![[Screenshot 2024-06-03 at 14.11.19.png]]

**Packet VS Circuit:**
![[Screenshot 2024-06-03 at 14.16.06.png]]

---

![[Screenshot 2024-06-03 at 14.15.34.png]]

### Performance

![[Screenshot 2024-06-03 at 14.19.36.png]]![[Screenshot 2024-06-03 at 14.19.59.png]]
![[Screenshot 2024-06-03 at 14.20.14.png]]

**Packet-Queuing Delay**:
![[Screenshot 2024-06-03 at 14.21.09.png]]

**Bottlenecks**:
![[Screenshot 2024-06-03 at 14.26.48.png]]

---

### Protocol

![[Screenshot 2024-06-03 at 14.31.41.png]]
![[Screenshot 2024-06-03 at 14.34.58.png]]
![[Screenshot 2024-06-03 at 14.34.25.png]]

## Chapter 2

### Network-Layer
- **forwarding**: move packets from a router's input link to appropriate router output link
- **routing**: determine route taken by packets from source to destination
	- routing algorithms
![[Screenshot 2024-06-03 at 19.48.31.png]]
![[Screenshot 2024-06-03 at 19.50.29.png]]
![[Screenshot 2024-06-03 at 19.50.42.png]]

---

### Router Architecture
![[Screenshot 2024-06-03 at 19.58.46.png]]
![[Screenshot 2024-06-03 at 19.59.02.png]]
![[Screenshot 2024-06-03 at 19.59.48.png]]
![[Screenshot 2024-06-03 at 20.00.08.png]]

---

![[Screenshot 2024-06-03 at 20.01.59.png]]
![[Screenshot 2024-06-03 at 20.02.29.png]]
![[Screenshot 2024-06-03 at 20.03.11.png]]
![[Screenshot 2024-06-03 at 20.04.51.png]]
![[Screenshot 2024-06-03 at 20.05.38.png]]

---

### IP (Internet Protocol)

![[Screenshot 2024-06-03 at 21.02.03.png]]
![[Screenshot 2024-06-03 at 21.03.34.png]]

**IP Address**: is a 32-bit identifier.
![[Screenshot 2024-06-03 at 21.06.35.png]]
![[Screenshot 2024-06-10 at 15.03.01.png]]
![[Screenshot 2024-06-03 at 21.25.42.png]]
![[Screenshot 2024-06-03 at 21.25.54.png]]
![[Screenshot 2024-06-03 at 21.26.22.png]]
![[Screenshot 2024-06-03 at 21.26.39.png]]

---

### IP Forwarding

**Forwarding**:
![[Screenshot 2024-06-03 at 21.34.50.png]]

**Routing**:
![[Screenshot 2024-06-03 at 21.36.09.png]]

**Algorithms**:
![[Screenshot 2024-06-03 at 21.37.36.png]]
![[Screenshot 2024-06-03 at 21.37.55.png]]
![[Screenshot 2024-06-03 at 21.40.00.png]]

---

### NAT (Network Address Translation)
![[Screenshot 2024-06-03 at 21.40.50.png]]
![[Screenshot 2024-06-03 at 21.41.48.png]]
![[Screenshot 2024-06-03 at 21.42.37.png]]

---

### IPv6

![[Screenshot 2024-06-03 at 21.47.30.png]]
![[Screenshot 2024-06-03 at 21.47.05.png]]

---

### Generalised Forwarding

![[Screenshot 2024-06-03 at 21.50.41.png]]
![[Screenshot 2024-06-03 at 21.50.48.png]]
![[Screenshot 2024-06-03 at 21.51.01.png]]
![[Screenshot 2024-06-03 at 21.51.41.png]]

---

## Chapter 3

![[Screenshot 2024-06-04 at 18.48.54.png]]
![[Screenshot 2024-06-04 at 18.51.13.png]]
![[Screenshot 2024-06-04 at 18.58.05.png]]

---

### Error Detection

![[Screenshot 2024-06-04 at 19.01.12.png]]
![[Screenshot 2024-06-04 at 19.03.51.png]]
![[Screenshot 2024-06-04 at 19.04.52.png]]
![[Screenshot 2024-06-04 at 19.08.15.png]]

---

### Multiple Access Protocols

![[Screenshot 2024-06-04 at 19.09.09.png]]
![[Screenshot 2024-06-04 at 19.13.27.png]]
![[Screenshot 2024-06-04 at 19.13.15.png]]

**TDMA**:
![[Screenshot 2024-06-04 at 19.14.05.png]]

**FDMA**:
![[Screenshot 2024-06-04 at 19.14.25.png]]

**Random Access Protocols**:
![[Screenshot 2024-06-04 at 19.15.35.png]]
![[Screenshot 2024-06-04 at 19.17.33.png]]
![[Screenshot 2024-06-04 at 19.18.21.png]]
![[Screenshot 2024-06-04 at 19.20.02.png]]
![[Screenshot 2024-06-04 at 19.21.24.png]]

**Taking turns**:
![[Screenshot 2024-06-04 at 19.23.19.png]]
![[Screenshot 2024-06-04 at 19.23.59.png]]

**Summary**:
![[Screenshot 2024-06-04 at 19.22.38.png]]
![[Screenshot 2024-06-04 at 19.28.24.png]]

---

![[Screenshot 2024-06-04 at 19.27.08.png]]

---

### LANs
![[Screenshot 2024-06-04 at 19.31.17.png]]
![[Screenshot 2024-06-04 at 19.31.51.png]]

---

![[Screenshot 2024-06-04 at 19.33.07.png]]
![[Screenshot 2024-06-04 at 19.34.19.png]]
![[Screenshot 2024-06-04 at 19.34.28.png]]
![[Screenshot 2024-06-04 at 19.34.44.png]]

---

### Ethernet

![[Screenshot 2024-06-04 at 19.39.16.png]]

![[Screenshot 2024-06-04 at 19.41.34.png]]
![[Screenshot 2024-06-04 at 19.41.43.png]]

![[Screenshot 2024-06-04 at 19.42.53.png]]
![[Screenshot 2024-06-04 at 19.43.07.png]]

---

### Switches
![[Screenshot 2024-06-04 at 19.46.17.png]]
![[Screenshot 2024-06-04 at 19.47.11.png]]
![[Screenshot 2024-06-04 at 19.52.02.png]]
![[Screenshot 2024-06-04 at 19.51.52.png]]
![[Screenshot 2024-06-04 at 19.52.13.png]]
![[Screenshot 2024-06-04 at 19.56.39.png]]

---

### VLANs
![[Screenshot 2024-06-04 at 20.57.21.png]]
![[Screenshot 2024-06-04 at 20.58.18.png]]
![[Screenshot 2024-06-04 at 20.59.00.png]]

---

## Chapter 4

### Wireless

![[Screenshot 2024-06-05 at 13.49.00.png]]
![[Screenshot 2024-06-05 at 13.50.04.png]]

**Handoff**:
![[Screenshot 2024-06-05 at 13.50.41.png]]

**Ad Hoc**:
![[Screenshot 2024-06-05 at 13.51.49.png]]

![[Screenshot 2024-06-05 at 13.52.26.png]]

---

### Wireless Link Characteristics

![[Screenshot 2024-06-05 at 13.53.19.png]]

![[Screenshot 2024-06-05 at 13.56.20.png]]![[Screenshot 2024-06-05 at 13.56.32.png]]

![[Screenshot 2024-06-05 at 13.56.41.png]]

![[Screenshot 2024-06-05 at 13.56.52.png]]
![[Screenshot 2024-06-05 at 13.58.32.png]]

### 802.11 WiFi

![[Screenshot 2024-06-05 at 14.00.20.png]]
![[Screenshot 2024-06-05 at 14.02.33.png]]
![[Screenshot 2024-06-05 at 14.02.48.png]]
![[Screenshot 2024-06-05 at 14.03.55.png]]
![[Screenshot 2024-06-05 at 14.06.02.png]]
![[Screenshot 2024-06-05 at 14.07.15.png]]

![[Screenshot 2024-06-05 at 14.09.35.png]]
![[Screenshot 2024-06-05 at 14.10.05.png]]

![[Screenshot 2024-06-05 at 14.12.50.png]]
![[Screenshot 2024-06-05 at 14.13.04.png]]
