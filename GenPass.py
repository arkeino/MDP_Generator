import random
import string

PASSWORD_LENGTH = 22

def generate_random_char(charset):
    return random.choice(charset)

def shuffle_password(password):
    password_list = list(password)
    random.shuffle(password_list)
    return ''.join(password_list)

def generate_password():
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    digits = string.digits
    special_chars = "!@#$%^&*()-_=+[]{};:,.<>?"

    password = [
        generate_random_char(uppercase),
        generate_random_char(digits),
        generate_random_char(digits),
        generate_random_char(digits),
        generate_random_char(special_chars),
    ]

    for _ in range(5, PASSWORD_LENGTH):
        rand_choice = random.randint(0, 3)
        if rand_choice == 0:
            password.append(generate_random_char(lowercase))
        elif rand_choice == 1:
            password.append(generate_random_char(uppercase))
        elif rand_choice == 2:
            password.append(generate_random_char(digits))
        elif rand_choice == 3:
            password.append(generate_random_char(special_chars))

    password = shuffle_password(password)

    return password

random.seed()
password = generate_password()
print(f"Mot de passe généré : {password}")
