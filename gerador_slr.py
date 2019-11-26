from bs4 import BeautifulSoup #Precisa instalar com $ pip3 install bs4

doc = open('SLR Parser Generator.html', 'r').read()

parsed_doc = BeautifulSoup(doc, 'html.parser')

print(doc)
