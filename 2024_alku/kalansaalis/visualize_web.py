import pygame
import json

with open("output.json", "r") as f:
    web = json.load(f)

hex_grid = []

rows = len(web) - 1
cols = len(web[0]) - (rows + 1)//2

print(cols)

for i in range(rows):
    hex_grid.append(web[i + 1][((i+1)//2) + 1:((i+1)//2) + cols + 1])

print(hex_grid)

square_size = 60

WHITE = (255, 255, 255)
GREY = (128, 128, 128)
BLACK = (0, 0, 0)


pygame.init()

font = pygame.font.Font(None, 34)

screen = pygame.display.set_mode((len(web[0])*square_size, rows*square_size))
pygame.display.set_caption("visualization")

for row in range(rows):
    for col in range(cols):
        x = square_size * col + ((row+1)//2) * square_size
        y = square_size * row
        
        pygame.draw.rect(
            screen, WHITE, (x, y, square_size, square_size)
        )
        pygame.draw.rect(
            screen, BLACK, (x, y, square_size, square_size), width=2
        )
        
        text = font.render(str(
            hex_grid[row][col]
            ), True, (255, 0, 0))
        
        text_rect = text.get_rect(
                        center=(
                            x + square_size * 3 // 4,
                            y + square_size * 3 // 4,
                        )
                    )
        screen.blit(text, text_rect)


pygame.display.flip()
        
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False