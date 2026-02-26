""" This Python program opens a file and asks the user to enter one or more letters.
These entered letters are converted to uppercase in all the text contained in the file.
A new file containing the modifications is created. """

import time

# Open and read the input file.
with open ("Texte_1_entree.txt", 'r') as T1E:
    texte = T1E.read()

# User input and basic validation.
entree = input('Entrer la ou les lettres à convertir en majuscule : ')
while not entree.isalpha():
    entree = input('Il faut entrer quelque chose qui est seulement composé de lettres : ')

# Modify the characters.
texte_mod = ""
i = 0
debut = time.perf_counter() # Start performance measurement of the processing.
while i < len(texte):
    if texte[i:i+len(entree)] == entree:
        texte_mod += entree.upper()
        i += len(entree)
    else:
        texte_mod += texte[i]
        i += 1

# Open/create and write to the output file.
with open ("Texte_1_sortie.txt", 'w') as T1S:
    for element in texte_mod:
        T1S.write(element)

# End performance measurement and display the result.
fin = time.perf_counter()
print(f"Temps de traitement : {fin - debut:.6f} secondes")