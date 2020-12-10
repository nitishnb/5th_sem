def start():
    output_rate = int(input("Enter output rate : "))
    size = int(input("Enter bucket Size : "))
    n = int(input("Enter no. of packets : "))
    for i in range(n):
        pac_size = int(input("Packet no %d Packet size : " % i))
        if pac_size > size:
            print("Bucket Overflow")
            break
        if pac_size <= output_rate:
            print("Bucket output successful"
                  "\nLast %d bytes sent" % pac_size)
        elif pac_size <= size:
            print("Bucket output successful"
                  "\n%d bytes outputted."
                  "\nLast %d bytes sent"
                  % (output_rate, pac_size - output_rate))

start()