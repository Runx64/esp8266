from tkinter import *

mocha_cnt = 0
capuccino_cnt = 0
latte_cnt = 0
espresso_cnt = 0
total_cnt = 0

def mocha_click():
    global mocha_cnt
    global total_cnt
    mocha_cnt += 1
    total_cnt += 25
    tv_mocha.set(mocha_cnt)
    
    
def capuccino_click():
    global capuccino_cnt
    global total_cnt
    capuccino_cnt += 1
    total_cnt += 35
    tv_capuccino.set(capuccino_cnt)
    
    
def latte_click():
    global latte_cnt
    global total_cnt
    latte_cnt += 1
    total_cnt += 30
    tv_latte.set(latte_cnt)
    
    
def espresso_click():
    global espresso_cnt
    global total_cnt
    espresso_cnt += 1
    total_cnt += 40
    tv_espresso.set(espresso_cnt)
    
def calculate_click():
    global total_cnt
    tv_total.set("total %s"%total_cnt)
    
def deletemocha_click():
    global mocha_cnt
    global total_cnt
    mocha_cnt -= 1
    total_cnt -= 25
    tv_mocha.set(mocha_cnt)

def deletecapuccino_click():
    global capuccino_cnt
    global total_cnt
    capuccino_cnt -= 1
    total_cnt -= 35
    tv_capuccino.set(capuccino_cnt)

def deletelatte_click():
    global latte_cnt
    global total_cnt
    latte_cnt -= 1
    total_cnt -= 30
    tv_latte.set(latte_cnt)
    
def deleteespresso_click():
    global espresso_cnt
    global total_cnt
    espresso_cnt -= 1
    total_cnt -= 40
    tv_espresso.set(espresso_cnt)

root = Tk()
root.option_add("*Font","consolas 25")

tv_mocha = IntVar()
tv_capuccino = IntVar()
tv_latte = IntVar()
tv_espresso = IntVar()
tv_total = StringVar()

Label(root, text="            ราคากาแฟ            ",fg="white",bg="saddle brown").grid(row=0,column=0,columnspan=4)

Label(root, text="มอคค่า",fg="black",bg="white").grid(row=1,column=0)
Label(root, text="คาปูชิโน่",fg="black",bg="white").grid(row=1,column=1,columnspan=1)
Label(root, text="ลาเต้",fg="black",bg="white").grid(row=1,column=2,columnspan=1)
Label(root, text="เอสเพรสโซ่",fg="black",bg="white").grid(row=1,column=3,columnspan=1)

Label(root, text="25",fg="black",bg="white").grid(row=2,column=0)
Label(root, text="35",fg="black",bg="white").grid(row=2,column=1,columnspan=1)
Label(root, text="30",fg="black",bg="white").grid(row=2,column=2,columnspan=1)
Label(root, text="40",fg="black",bg="white").grid(row=2,column=3,columnspan=1)

Label(root, text="บาท",fg="black",bg="white").grid(row=3,column=0)
Label(root, text="บาท",fg="black",bg="white").grid(row=3,column=1,columnspan=1)
Label(root, text="บาท",fg="black",bg="white").grid(row=3,column=2,columnspan=1)
Label(root, text="บาท",fg="black",bg="white").grid(row=3,column=3,columnspan=1)

Label(root, text="วิธีการกดคำนวณกาแฟ",fg="black",bg="white").grid(row=5,column=0,columnspan=4)
Label(root, text="1.กดที่ปุ่มของกาแฟแต่ละชนิดกด 1 ครั้งคือกาแฟชนิดนั้น 1 แก้ว",fg="black",bg="white").grid(row=6,columnspan=4)
Label(root, text="2.กดที่คำนวณเพื่อหาราคากาแฟทั้งหมด   ",fg="black",bg="white").grid(row=7,columnspan=3)

Button(root, text="มอคค่า",fg="white",bg="darkgoldenrod4",command=mocha_click).grid(row=8,column=0)
Button(root, text="คาปูชิโน่",fg="white",bg="burlywood",command=capuccino_click).grid(row=8,column=1)
Button(root, text="ลาเต้",fg="white",bg="peru",command=latte_click).grid(row=8,column=2)
Button(root, text="เอสเพรสโซ่",fg="white",bg="sienna",command=espresso_click).grid(row=8,column=3)

Button(root, text="delete",fg="white",bg="darkgoldenrod4",command=deletemocha_click).grid(row=10,column=0)
Button(root, text="delete",fg="white",bg="burlywood",command=deletecapuccino_click).grid(row=10,column=1)
Button(root, text="delete",fg="white",bg="peru",command=deletelatte_click).grid(row=10,column=2)
Button(root, text="delete",fg="white",bg="sienna",command=deleteespresso_click).grid(row=10,column=3)

Button(root, text="คำนวณ",fg="white",bg="gold",command=calculate_click).grid(row=11,columnspan=2)
                                                                 
Label(root,textvariable=tv_mocha,bg="white").grid(row=9,column=0)
Label(root,textvariable=tv_capuccino,bg="white").grid(row=9,column=1)
Label(root,textvariable=tv_latte,bg="white").grid(row=9,column=2)
Label(root,textvariable=tv_espresso,bg="white").grid(row=9,column=3)

Label(root,textvariable=tv_total,bg="white").grid(row=11,column=2,columnspan=2)

root.mainloop()