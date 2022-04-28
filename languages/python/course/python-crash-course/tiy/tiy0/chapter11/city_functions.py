"""A collection of functions for working with cities."""


def city_country(city, country, population=None):
    """Return a string like 'Santiago, Chile'."""
    if population:
        return f"{city.title()}, {country.title()} - Population {population}"
    else:
        return f"{city.title()}, {country.title()}"
