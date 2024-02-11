import pygame
import random
import string
import time

# Initialize pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
FPS = 60
FONT_SIZE = 40
LETTER_SPEED = 7  # Pixels per frame
LETTER_FREQUENCY = 40  # Frequency of new letters (in frames)
REACTION_THRESHOLD = 3  # Reaction time threshold in seconds
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Set up the display
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Sustained Attention Task")
clock = pygame.time.Clock()

# Load fonts
font = pygame.font.SysFont(None, FONT_SIZE)

# Function to generate random letters
def generate_letter():
    return random.choice(string.ascii_uppercase)

# Function to display text
def draw_text(text, x, y):
    surface = font.render(text, True, BLACK)
    screen.blit(surface, (x, y))

# Function to display last reaction time
def display_last_reaction_time(last_reaction_time):
    text = f"Last Reaction Time: {last_reaction_time:.2f} seconds"
    draw_text(text, 10, 10)

# Main game loop
running = True
counter = 0
letters = []
x_appeared_time = None
last_reaction_time = None

# Open the file to write results
with open('attention_results.txt', 'w') as file:
    file.write("Results for Sustained Attention Task\n\n")

while running:
    counter += 1

    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                if x_appeared_time is not None:
                    reaction_time = time.time() - x_appeared_time
                    last_reaction_time = reaction_time
                    if reaction_time > REACTION_THRESHOLD:
                        with open('attention_results.txt', 'a') as file:
                            file.write("Fail: Reaction time exceeded 3 seconds\n")
                    else:
                        with open('attention_results.txt', 'a') as file:
                            file.write(f"Reaction time: {reaction_time:.2f} seconds\n")
                    x_appeared_time = None
                else:
                    with open('attention_results.txt', 'a') as file:
                        file.write("Fail: Spacebar pressed without 'X'\n")

    # Clear the screen
    screen.fill(WHITE)

    # Generate new letters
    if counter % LETTER_FREQUENCY == 0:
        new_letter = generate_letter()
        if new_letter == 'X':
            x_appeared_time = time.time()
        letters.append((new_letter, WIDTH))

    # Update and draw letters
    for i in range(len(letters) - 1, -1, -1):
        letter, x = letters[i]
        draw_text(letter, x, HEIGHT // 2 - FONT_SIZE // 2)
        x -= LETTER_SPEED
        letters[i] = (letter, x)
        if x + FONT_SIZE < 0:
            letters.pop(i)

    # Display last reaction time
    if last_reaction_time is not None:
        display_last_reaction_time(last_reaction_time)

    # Update the display
    pygame.display.flip()
    clock.tick(FPS)

# Quit pygame
pygame.quit()

