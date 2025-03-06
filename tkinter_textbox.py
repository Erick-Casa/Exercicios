import tkinter

def submit():
    selecionados = listbox.curselection()
    
    for indice in selecionados:
        print(listbox.get(indice))

def add():
    algo = entrybox.get().strip()
    if algo:
        listbox.insert(listbox.size(), entrybox.get())
        listbox.config(height=listbox.size())

def delete():
    selecionados = listbox.curselection()
    
    for indice in reversed(selecionados):
        listbox.delete(indice)
        
    listbox.config(height=listbox.size())

def change():
    selecionados = listbox.curselection()

    if listbox2.size() + len(selecionados) <= 3: #verificar se lista2 ta no limite
        for indice in selecionados:
            listbox2.insert(tkinter.END, listbox.get(indice))

        for indice in reversed(selecionados):
            listbox.delete(indice)

    selecionados_2 = listbox2.curselection()

    for indice in selecionados_2:
        listbox.insert(tkinter.END, listbox2.get(indice))

    for indice in reversed(selecionados_2):
        listbox2.delete(indice)
    

root = tkinter.Tk()
root.geometry("400x550")
root.title("Textbox Test")


listbox = tkinter.Listbox(root,
                          bg="lightgray",
                          font=("Constantia", "20"),
                          width=15,
                          selectmode=tkinter.MULTIPLE)
listbox.config(height=listbox.size())
listbox.pack()

listbox.insert(0, "pizza")
listbox.insert(1, "hambúrguer")
listbox.insert(2, "hotdog")
listbox.insert(3, "coxinha")

listbox2 = tkinter.Listbox(root,
                          bg="lightgray",
                          font=("Constantia", "20"),
                          width=15,
                          selectmode=tkinter.MULTIPLE)
listbox2.config(height=listbox.size())
listbox2.pack()

button_change = tkinter.Button(root, text="Change Item", command=change)
button_change.pack()

button = tkinter.Button(root, text="Submit", command=submit)
button.pack()

entrybox = tkinter.Entry(root)
entrybox.pack()

button_add = tkinter.Button(root, text="Add", command=add)
button_add.pack()

button_delete = tkinter.Button(root, text="Delete", command=delete)
button_delete.pack()


root.mainloop()
