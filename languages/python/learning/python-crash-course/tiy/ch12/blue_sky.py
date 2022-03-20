import sys
import pygame
from ship import Ship
from settings import Settings


class BlueSky:
    def __init__(self):

        pygame.init()

        self.screen = pygame.display.set_mode((1200, 800))
        pygame.display.set_caption("Blue Sky")

        self.settings = Settings()

        self.bg_color = (0, 0, 128)
        self.ship = Ship(self)

    def run_game(self):

        while True:

            self._check_events()
            self.ship.update()
            self._update_screen()

    def _check_events(self):

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                self._check_keyup_events(event)

    def _check_keydown_events(self, event):

        if event.key == pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left == True
        elif event.key == pygame.K_RIGHT:
            self.ship.moving_right == True
        elif event.key == pygame.K_UP:
            self.ship.moving_up == True
        elif event.key == pygame.K_DOWN:
            self.ship.moving_down == True

    def _check_keyup_events(self, event):

        if event.key == pygame.K_LEFT:
            self.ship.moving_left == False
        elif event.key == pygame.K_RIGHT:
            self.ship.moving_right == False
        elif event.key == pygame.K_UP:
            self.ship.moving_up == False
        elif event.key == pygame.K_DOWN:
            self.ship.moving_down == False

    def _update_screen(self):

        self.screen.fill(self.bg_color)
        self.ship.blitme()
        pygame.display.flip()


if __name__ == "__main__":
    blue_sky = BlueSky()
    blue_sky.run_game()
