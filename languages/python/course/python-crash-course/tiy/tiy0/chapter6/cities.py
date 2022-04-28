cities = {
    "santiago": {
        "country": "chile",
        "population": 6158080,
        "nearby mountains": "andes",
    },
    "talkeetna": {
        "country": "alaska",
        "population": 876,
        "nearby mountains": "alaska range",
    },
    "kathmandu": {
        "country": "nepal",
        "population": 1003285,
        "nearby mountains": "himilaya",
    },
}

for city, info in cities.items():
    print(f"\n{city.title()} is in {info['country'].title()}.")
    print(f"  It has a population of about {info['population']}.")
    print(f"  The {info['nearby mountains'].title()} are nearby.")
