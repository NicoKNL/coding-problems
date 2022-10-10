if __name__ == '__main__':
    N = int(input())
    arr = []
    for _ in range(N):
        cmd = input().split()
        
        if cmd[0] == "print":
            print(arr)
        
        if cmd[0] == "insert":
            arr.insert(int(cmd[1]), int(cmd[2]))
    
        if cmd[0] == "pop":
            arr.pop()
        
        if cmd[0] == "append":
            arr.append(int(cmd[1]))
        
        if cmd[0] == "sort":
            arr = sorted(arr)

        if cmd[0] == "reverse":
            arr = list(reversed(arr))
        
        if cmd[0] == "remove":
            arr.remove(int(cmd[1]))