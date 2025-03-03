import tkinter

goals = 0

def button_click():
    global goals
    print("Gol!")
    goals += 1
    label.config(text=goals)

window = tkinter.Tk()

picture = tkinter.PhotoImage(file="soccer_ball.png")
picture = picture.subsample(x=8,y=8)

window.title("Janela Nome")
window.geometry("600x400")
window.config(background="lightblue")
window.iconphoto(True, picture)

button = tkinter.Button(window,
                        text="Clique",
                        font=("Ink Free", 20, "bold"),
                        bg="black", fg='white',
                        activebackground="darkgray",
                        activeforeground='lightgray',
                        image=picture, compound="right",
                        state=tkinter.ACTIVE)
button.pack()

label = tkinter.Label(window, text=goals, font=("courier, 20"))
label.pack()


button.config(command=button_click)

window.mainloop()


