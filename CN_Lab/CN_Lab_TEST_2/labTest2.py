def start():
    output_rate = 42
    size = 400
    n = 3
    packets = [60, 300, 600]
    print("The maximum space of receiver’s buffer is %d kb" %(size))
    print("The output rate is %d Kbps." %(output_rate))
    print()
    for i in range(n):
        pac_size = packets[i]
        print("Packet no %d Packet size : %d kb" % (i+1, pac_size))
        if pac_size > size:
            print("Bucket Overflow")
            break
        if pac_size <= output_rate:
            print("Bucket output successful"
                  "\nLast %d kb sent" % pac_size)
        elif pac_size <= size:
            print("Bucket output successful"
                  "\n%d kb outputted."
                  "\nLast %d kb sent"
                  % (output_rate, pac_size - output_rate))
        print()

start()