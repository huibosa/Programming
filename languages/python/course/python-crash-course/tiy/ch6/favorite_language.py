favorite_languages = {
    "jen": ["python", "ruby"],
    "sarah": ["c"],
    "edward": ["ruby", "go"],
    "phil": ["python", "haskell"],
}

for name, languages in favorite_languages.items():
    if len(languages) > 1:
        print(f"\n{name.title()}'s favorite language are:")

        for language in languages:
            print(language.title())
    else:
        print(f"\n{name.title()}'s favorite language is {language.title()}")
