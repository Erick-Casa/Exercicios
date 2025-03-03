import tkinter

window = tkinter.Tk()

window.title("Janela de Teste")
window.geometry("500x300")
window.config(background="lightblue") #ou endereço hex

icon = tkinter.PhotoImage(file="soccer_ball.png") #endereço imagem
icon = icon.subsample(8,8)

window.iconphoto(True, icon)

label = tkinter.Label(window,
                      text="Teste de Texto Aumentado",
                      font=("Arial", 20, "bold"),
                      fg="brown", bg="yellow",
                      bd=5, relief ="groove",
                      padx=10, pady=10,
                      image=icon, compound="bottom")
label.pack()

window.mainloop()
