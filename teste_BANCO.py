import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
import sqlite3

# Configuração do banco de dados
def create_table():
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS products (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        code TEXT NOT NULL,
        description TEXT NOT NULL,
        price REAL NOT NULL
    )
    ''')
    
    conn.commit()
    conn.close()

create_table()

# Funções do banco de dados
def add_product(code, description, price):
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    INSERT INTO products (code, description, price)
    VALUES (?, ?, ?)
    ''', (code, description, price))
    
    conn.commit()
    conn.close()

def get_product(product_id):
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    SELECT * FROM products WHERE id=?
    ''', (product_id,))
    
    product = cursor.fetchone()
    conn.close()
    
    return product

def get_product_by_code(code):
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    SELECT * FROM products WHERE code=?
    ''', (code,))
    
    product = cursor.fetchone()
    conn.close()
    
    return product

def get_all_products():
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    SELECT * FROM products
    ''')
    
    products = cursor.fetchall()
    conn.close()
    
    return products

def update_product(product_id, code, description, price):
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    UPDATE products
    SET code=?, description=?, price=?
    WHERE id=?
    ''', (code, description, price, product_id))
    
    conn.commit()
    conn.close()

def delete_product(product_id):
    conn = sqlite3.connect('banco.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    DELETE FROM products WHERE id=?
    ''', (product_id,))
    
    conn.commit()
    conn.close()

# Funções da interface gráfica
def add_product_interface():
    code = code_entry.get()
    description = description_entry.get()
    price = price_entry.get()

    if code and description and price:
        try:
            existing_product = get_product_by_code(code)
            if not existing_product:
                add_product(code, description, float(price))
                result_label.config(text=f"Código: {code}, Descrição: {description}, Preço: {price}")
                messagebox.showinfo("Sucesso", "Produto incluído com sucesso!")
                code_entry.delete(0, tk.END)
                description_entry.delete(0, tk.END)
                price_entry.delete(0, tk.END)
                update_product_list()
            else:
                messagebox.showerror("Erro", "Código de produto já existe.")
        except ValueError:
            messagebox.showerror("Erro", "Valor unitário inválido.")
    else:
        messagebox.showerror("Erro", "Todos os campos são obrigatórios.")

def consult_product_interface():
    product_id = id_entry.get()
    if product_id:
        product = get_product(int(product_id))
        if product:
            result_label.config(text=f"ID: {product[0]}, Código: {product[1]}, Descrição: {product[2]}, Preço: {product[3]}")
        else:
            result_label.config(text="Produto não encontrado.")
    else:
        messagebox.showerror("Erro", "ID do produto é obrigatório.")

def update_product_interface():
    product_id = id_entry.get()
    code = code_entry.get()
    description = description_entry.get()
    price = price_entry.get()

    if product_id and code and description and price:
        try:
            update_product(int(product_id), code, description, float(price))
            messagebox.showinfo("Sucesso", "Produto alterado com sucesso!")
            code_entry.delete(0, tk.END)
            description_entry.delete(0, tk.END)
            price_entry.delete(0, tk.END)
            update_product_list()
        except ValueError:
            messagebox.showerror("Erro", "Valor unitário inválido.")
    else:
        messagebox.showerror("Erro", "Todos os campos são obrigatórios.")

def delete_product_interface():
    product_id = id_entry.get()
    if product_id:
        delete_product(int(product_id))
        messagebox.showinfo("Sucesso", "Produto excluído com sucesso!")
        id_entry.delete(0, tk.END)
        update_product_list()
    else:
        messagebox.showerror("Erro", "ID do produto é obrigatório.")

def update_product_list():
    for i in tree.get_children():
        tree.delete(i)
    products = get_all_products()
    for product in products:
        tree.insert("", "end", values=(product[0], product[1], product[2], product[3]))

# Configuração da interface gráfica
root = tk.Tk()
root.title("Sistema de Vendas")

# Widgets da interface
tk.Label(root, text="ID do Produto:").grid(row=0, column=0, padx=10, pady=10)
id_entry = tk.Entry(root)
id_entry.grid(row=0, column=1, padx=10, pady=10)

tk.Label(root, text="Código:").grid(row=1, column=0, padx=10, pady=10)
code_entry = tk.Entry(root)
code_entry.grid(row=1, column=1, padx=10, pady=10)

tk.Label(root, text="Descrição:").grid(row=2, column=0, padx=10, pady=10)
description_entry = tk.Entry(root)
description_entry.grid(row=2, column=1, padx=10, pady=10)

tk.Label(root, text="Preço:").grid(row=3, column=0, padx=10, pady=10)
price_entry = tk.Entry(root)
price_entry.grid(row=3, column=1, padx=10, pady=10)

tk.Button(root, text="Incluir Produto", command=add_product_interface).grid(row=4, column=0, padx=10, pady=10)
tk.Button(root, text="Consultar Produto", command=consult_product_interface).grid(row=4, column=1, padx=10, pady=10)
tk.Button(root, text="Alterar Produto", command=update_product_interface).grid(row=5, column=0, padx=10, pady=10)
tk.Button(root, text="Excluir Produto", command=delete_product_interface).grid(row=5, column=1, padx=10, pady=10)

result_label = tk.Label(root, text="")
result_label.grid(row=6, column=0, columnspan=2, padx=10, pady=10)

# Adicionando Treeview para mostrar a lista de produtos
columns = ("ID", "Código", "Descrição", "Preço")
tree = ttk.Treeview(root, columns=columns, show="headings")
tree.heading("ID", text="ID")
tree.heading("Código", text="Código")
tree.heading("Descrição", text="Descrição")
tree.heading("Preço", text="Preço")
tree.grid(row=7, column=0, columnspan=2, padx=10, pady=10)

# Atualizar lista de produtos na inicialização
update_product_list()

root.mainloop()
