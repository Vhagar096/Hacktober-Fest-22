import random

secret_number = random.randrange(0,100)

def guessing_game(secret_number,num_tries):
    
    if num_tries > 5:
        
        print('Sorry, you lose! Too many wrong guesses.')
                
    else:
                
        print('Attempt number',num_tries)
        
        guess = int(input())
        
        if guess == secret_number:
            print('Congratulations, you won! You guessed the secret number',secret_number,'in',num_tries,'guesses.')
            
        else: 
            
            if guess > secret_number and num_tries < 5:
                print('Try again! Your guess is too high.')
                
            elif guess < secret_number and num_tries < 5:
                print('Try again! Your guess is too low.')
        
            guessing_game(secret_number,num_tries+1)      

guessing_game(secret_number,1)
