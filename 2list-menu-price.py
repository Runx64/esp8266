menu=["SPAGHETTI TRUFFLE CREAM SAUCE","MATSUSAKA DON","LOBSTER SPAGHETTI","KANOM PRA PAI"]
price=[240,200,350,80]
print('Welcome to Restaurant')
print('---- Menu ----')
n=1
for i in menu:
    print("%d.%s"%(n,i))
    n+=1
order=int(input('Choose Menu: '))
print('Your Order :',menu[order-1])
print('Price :',price[order-1])