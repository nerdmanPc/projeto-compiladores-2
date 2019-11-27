from bs4 import BeautifulSoup #Precisa instalar com $ pip3 install bs4
from csv import writer

doc = open('SLR Parser Generator.html', 'r').read()

parsed_doc = BeautifulSoup(doc, 'html.parser')
tabela = parsed_doc.find('div', id = 'lrTableView').table

cabecalho = [ tabela.thead.find_all('tr')[1].th ]
cabecalho.extend (tabela.thead.find_all('tr')[2].find_all('th'))

linhas = tabela.tbody.find_all('tr') #linhas = lista de linhas
for linha in linhas:
    linha = linha.find_all('td') #linhas = lista de lista de celulas

texto_cabecalho = list(map(lambda celula : celula.get_text(), cabecalho))

texto_linhas = []
for linha in linhas:
    celulas = linha.find_all('td')
    aux_linha = list(map(lambda celula : celula.get_text(), celulas))
    texto_linhas.append(aux_linha)

with open('tabela_slr.csv', 'x') as csv_file:
    csv_writer = writer(csv_file)
    csv_writer.writerow(texto_cabecalho)
    for texto_linha in texto_linhas:
        csv_writer.writerow(texto_linha)
