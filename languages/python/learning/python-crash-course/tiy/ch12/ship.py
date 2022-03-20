import pygame


class Ship:
    def __init__(self, sky):

        self.screen = sky.screen
        self.screen_rect = sky.screen.get_rect()
        self.settings = sky.settings

        self.image = pygame.image.load("images/ship.bmp")
        self.rect = self.image.get_rect()

        self.rect.center = self.screen_rect.center

        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False

        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def update(self):

        if self.moving_right:
            self.x += self.settings.ship_speed
        if self.moving_left and self.rect.x > 0:
            self.x -= self.settings.ship_speed
        if self.moving_up and self.rect.y > 0:
            self.y -= self.settings.ship_speed
        if self.moving_left and self.rect.bottom < self.screen_rect.bottom:
            self.y += self.settings.ship_speed

        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):

        self.screen.blit(self.image, self.rect)
