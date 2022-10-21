n = int(input())

array = [i for i in range(1,n*1000) if str(i).count('666') == 1]
print(array[n-1])

