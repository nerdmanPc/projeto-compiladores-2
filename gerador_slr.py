from bs4 import BeautifulSoup #Precisa instalar com $ pip3 install bs4
from csv import writer

doc = open('SLR Parser Generator.html', 'r').read()

parsed_doc = BeautifulSoup(doc, 'html.parser')

tabela = parsed_doc.find('div', id = 'lrTableView').table
cabecalho = tabela.thead.contents[2].contents
cabecalho.insert(0, tabela.thead.contents[1].th)
linhas = tabela.tbody.contents

for celula in cabecalho:
    print (celula)

for ceula in linhas:
    print (celula)
