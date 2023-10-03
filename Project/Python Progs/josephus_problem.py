def Josh(person, k, index):
   
  
  if len(person) == 1:
    print(person[0])
    return
   
  
  index = ((index+k)%len(person))
   
  
  person.pop(index)

  Josh(person,k,index)
 
