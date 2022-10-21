import random
MaxR = 5 
MaxC = 5
MaxSpeed = 100
MaxSize = 10
R = random.randint(2, MaxR)
C = random.randint(2, MaxC)
M = random.randint(0, 3)

Z = [ str(i) for i in range(1, MaxSize+1) ]
random.shuffle(Z)
Z = Z[:M]

P = [ f"{i} {j}" for i in range(1, R+1) for j in range( 1, C+1) ]
random.shuffle(P)
P = P[:M]
Speed = random.randint(1, MaxSpeed)
D = random.randint(1,4)

print(R, C, M)
for i in range(M):
    print(f"{P[i]} {Speed} {D} {Z[i]}")
