a='helllllloooooo'
if len(a)>8:
  print(f'string has {len(a)} character and is too long')
if (n := len(a))>10:
  print(f"string has {n} character and is tooo long")
  #this := warnus operator is used when we compare and assign value togethers
#if (n=len(a))>8 this gives error thast why we use walrus operator
while ((n:=len(a))>1):
  print(n)
  a=a[:-1]
print(a)
