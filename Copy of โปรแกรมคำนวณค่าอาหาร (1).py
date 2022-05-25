from tkinter import *
food={}
drinks={}
price=[]
global steakn, saladn, soupn, pastan, friesn, chickenn, hamburgern, watern, winen, beern, milkshaken, juicen
steakn = saladn = soupn = pastan = friesn = chickenn = hamburgern = watern = winen = beern = milkshaken = juicen = 0
root=Tk()
global order
order = 0

frame = Frame(root)
root.rowconfigure(0, weight=1)
root.columnconfigure(0, weight=1)
frame.grid(row=0, column=0, sticky="news")
root.title("Restaurant")

root.option_add("*font", "JasmineUPC 28")
Label(frame,text="สามารถรับใบเสร็จได้ที่ Thonny", fg="SandyBrown", padx=20, pady=20).grid(row=1,column=2)
root.option_add("*font", "JasmineUPC 18")

def steak():
    global steakn, order
    steakn += 1
    food['steak'] = "สเต็ก {} จาน".format(steakn)
    price.append(239)
    order += 1
def salad():
    global saladn, order
    saladn += 1
    food['salad'] = "สลัด {} จาน".format(saladn)
    price.append(89)
    order += 1
def soup():
    global soupn, order
    soupn += 1
    food['soup'] = "ซุป {} ถ้วย".format(soupn)
    price.append(99)
    order += 1
def pasta():
    global pastan, order
    pastan += 1
    food['pasta'] = "พาสต้า {} จาน".format(pastan)
    price.append(119)
    order += 1
def frenchfries():
    global friesn, order
    friesn += 1
    food['fries'] = "เฟรนช์ฟรายส์ {} ถาด".format(friesn)
    price.append(59)
    order += 1
def freidchicken():
    global chickenn, order
    chickenn += 1
    food['chicken'] = "ไก่ทอด {} จาน".format(chickenn)
    price.append(189)
    order += 1
def hamburger():
    global hamburgern, order
    hamburgern += 1
    food['hamburger'] = "แฮมเบอร์เกอร์ {} ชิ้น".format(hamburgern)
    price.append(89)
    order += 1
def water():
    global watern, order
    watern += 1
    drinks['water'] = "น้ำเปล่า {} ขวด".format(watern)
    price.append(19)
    order += 1
def wine():
    global winen, order
    winen += 1
    drinks['wine'] = "ไวน์ {} แก้ว".format(winen)
    price.append(279)
    order += 1
def beer():
    global beern, order
    beern += 1
    drinks['beer'] = "เบียร์ {} แก้ว".format(beern)
    price.append(89)
    order += 1
def milkshake():
    global milkshaken, order
    milkshaken += 1
    drinks['milkshake'] = "มิลค์เชค {} แก้ว".format(milkshaken)
    price.append(89)
    order += 1
def juice():
    global juicen, order
    juicen += 1
    drinks['juice'] = "น้ำผลไม้ {} แก้ว".format(juicen)
    price.append(49)
    order += 1

def cancel():
    global steakn, saladn, soupn, pastan, friesn, chickenn, hamburgern, watern, winen, beern, milkshaken, juicen, order
    steakn = saladn = soupn = pastan = friesn = chickenn = hamburgern = watern = winen = beern = milkshaken = juicen = order = 0
    food.clear()
    drinks.clear()
    price.clear()

def total():
    print("----Welcome to Restaurant----")
    for _,v in food.items():
        print(v)
    for _,v in drinks.items():
        print(v)
    if(sum(price)>0):
        print("ออเดอร์ทั้งหมด : ",order,"อย่าง")
        if(sum(price)>=1000):
            price1=(sum(price)*(10/100))
            price2=(sum(price)-(price1))
            print("เมื่อทานครบ 1,000 บาท ได้รับส่วนลด 10 % รวมเป็นเงิน : ",price2,"บาท")
        else:
            print("รวมเป็นเงิน : ",sum(price),"บาท")

Button(frame,text='สเต็ก 1 จาน (239)',command=steak,bg="SlateGray1",activebackground="turquoise").grid(row=5,column=1,sticky="ew")
Button(frame,text="สลัด 1 จาน (89)",command=salad,bg="SlateGray1",activebackground="turquoise").grid(row=5,column=3,sticky="ew")
Button(frame,text="ซุป 1 ถ้วย (99)",command=soup,bg="SlateGray1",activebackground="turquoise").grid(row=5,column=2,sticky="ew")
Button(frame,text="พาสต้า 1 จาน (119)",command=pasta,bg="DarkSlateGray1",activebackground="turquoise").grid(row=6,column=1,sticky="ew")
Button(frame,text="เฟรนช์ฟรายส์ 1 ถาด (59)",command=frenchfries,bg="DarkSlateGray1",activebackground="turquoise").grid(row=6,column=2,sticky="ew")
Button(frame,text="ไก่ทอด 1 จาน (189)",command=freidchicken,bg="DarkSlateGray1",activebackground="turquoise").grid(row=6,column=3,sticky="ew")
Button(frame,text="แฮมเบอร์เกอร์ 1 ชิ้น (89)",command=hamburger,bg="DarkSlateGray2",activebackground="turquoise").grid(row=7,column=1,sticky="ew")
Button(frame,text="น้ำเปล่า 1 ขวด (19)",command=water,bg="DarkSlateGray2",activebackground="turquoise").grid(row=7,column=2,sticky="ew")
Button(frame,text="ไวน์ 1 แก้ว (279)",command=wine,bg="DarkSlateGray2",activebackground="turquoise").grid(row=7,column=3,sticky="ew")
Button(frame,text="เบียร์ 1 แก้ว (89)",command=beer,bg="DarkSlateGray3",activebackground="turquoise").grid(row=8,column=1,sticky="ew")
Button(frame,text="มิลค์เชค 1 แก้ว (89)",command=milkshake,bg="DarkSlateGray3",activebackground="turquoise").grid(row=8,column=2,sticky="ew")
Button(frame,text="น้ำผลไม้ 1 แก้ว (49)",command=juice,bg="DarkSlateGray3",activebackground="turquoise").grid(row=8,column=3,sticky="ew")
Button(frame,text="เช็คบิล",command=total,bg="DarkSlateGray4",activebackground="turquoise").grid(row=18,column=1,sticky="ew")
Button(frame,text="ยกเลิก",command=cancel,bg="DarkSlateGray4",activebackground="turquoise").grid(row=18,column=3,sticky="ew")

root.resizable(False, False)
root.mainloop()