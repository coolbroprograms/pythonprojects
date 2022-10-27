def sum(num1,num2):
  return num1+num2
total=sum(10,5)
print(sum(5,6))
print(total)
print(7,total)

def add(num1,num2):
  def another_func(num1,num2):
    return  num1+num2  #because we are just defining function not calling the function
new_total=add(2,5)
print(new_total) 

def func(num1,num2):
  def an_func(num1,num2):
    return num1+num2
  return an_func
total1=func(10,15)
print(total1)
print(total1(10,15))

def funct(num1,num2):
  def ano_func(num1,num2):
    return num1+num2
  return ano_func(num1,num2)
  return 5 #these two lines of fxn not executed as after return it will exit the function
  
  print('hello')
  
sum1=funct(10,25)
print(sum1)
