def josephus(n, k):
   arr = list(range(1, n + 1))
   result = []

   while arr:
       for i in range(len(arr)):
           if arr[i] == n:
               result.append(arr.pop(i))
               break
           else:
               arr[i] += 1
               if arr[i] > k:
                   result.append(arr.pop(i))
                   break

   return result

print(josephus(41, 3))