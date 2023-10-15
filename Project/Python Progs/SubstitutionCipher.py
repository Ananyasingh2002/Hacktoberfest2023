def caesar_cipher(text, shift):
    encrypted_text = ""
    
    for char in text:
        if char.isalpha():  # Check if the character is an alphabet letter
            if char.islower():
                shifted = (ord(char) - ord('a') + shift) % 26 + ord('a')
                encrypted_text += chr(shifted)
            elif char.isupper():
                shifted = (ord(char) - ord('A') + shift) % 26 + ord('A')
                encrypted_text += chr(shifted)
        else:
            encrypted_text += char  # Keep non-alphabet characters unchanged
    
    return encrypted_text

def caesar_decipher(text, shift):
    return caesar_cipher(text, -shift)

# Example usage
plaintext = "Hello, World!"
shift = 3
encrypted_text = caesar_cipher(plaintext, shift)
print("Encrypted: " + encrypted_text)

decrypted_text = caesar_decipher(encrypted_text, shift)
print("Decrypted: " + decrypted_text)
