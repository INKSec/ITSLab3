# ITS Lab3 Michael Burkhardt 

# Ceasar Cipher

# import module
from cryptography.fernet import Fernet



# Encryption Caesar

def caesar_encryption(plaintext, key):
    encryption_str = ''
    for i in plaintext:
        
            if i.isupper():
                temp = 65 + ((ord(i) - 65 + key) % 26) 
                encryption_str = encryption_str + chr(temp)   
            elif i.islower():
                temp = 97 + ((ord(i) - 97 + key) % 26)
                encryption_str = encryption_str + chr(temp)
            else:
                encryption_str += i

    print ("Der Ciphertext lautet:" ,encryption_str)
    return encryption_str

plaintext = input("Zu verschluesselnden Text eingeben: ")
key = int(input("Schluessel eingeben: "))
ciphertext = caesar_encryption(plaintext, key)



# Decryption Caesar


def caesar_decryption(ciphertext, key):
    decryption_str = ''
    for i in ciphertext:
        if i.isupper():
            if ((ord(i) - 65 - key) < 0):
                temp = 65 + ((ord(i) - 65 - key + 26) % 26) 
            else:
                temp = 65 + ((ord(i) - 65 - key) % 26) 
                decryption_str = decryption_str + chr(temp)                              
        elif i.islower():
            if ((ord(i) - 97 - key) < 0):
                temp = 97 + ((ord(i) - 97 - key + 26) % 26) 
            else:
                temp = 97 + ((ord(i) - 97 - key) % 26) 
                decryption_str = decryption_str + chr(temp)
        else:
                decryption_str = decryption_str + i  

    print ("Der Klartext lautet:" ,decryption_str)

abfrage = input("Wollen Sie den Text wieder entschluesseln? (j/n)")
if(abfrage == "j"):
   caesar_decryption(ciphertext, key)