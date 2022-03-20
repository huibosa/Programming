## Undoing Things

```
git commit --amend
```

### Unstaging a Staged File

```sh
git reset HEAD <file>
git restore --staged <file>
```

### Unmodifiying a Modified File

```sh
git checkout -- <file>
git restore <file>
```

## Working with Remotes

```sh
# show remote
git remote
git remote -v
# add remote
git remote add <shortname> <url>
# see more info about a paticular remote
git remote show <remote>
# rename and remove remote
git remote rename <remote> <newname>
git remote remote <remote>
```

```sh
git fetch <remote>
git pull
git push <remote> <branch>
```

```sh
# default behaviour of git
git config --global pull.rebase "false"
# rebase when pulling
git config --global pull.rebase "true"
```

### Tagging

```sh
git tag                 # list the existing tag
git tag -l <"tagname">  # listing tag wildcard
git show <tagname>      # show tag
```

```sh
git tag <tagname>-lw                # add a lightwight tag
git tag -a <tagname> -m <"message"> # add a annotated tag
git tag -a <tagname> <checksum>     # add tag to paticular commit
```

```sh
git push <remote> <tagname>     # push a specific tag
git push <remote> --tags        # push all tags
git push <remote> --follow-tags # push annotated tags only
```

```sh
git tag -d <tagname>                    # remove a tag
git push <remote> :refs/tags/<tagname>  # delete tag from remote server
```

```sh
git checkout <tagname>                  # checkout tags
git checkout -b <branchName> <tagname>  # switch to a new branch
```

## Git Branching

```sh
git branch <newBranch>      # create a new branch
git checkout <branch>       # move HEAD to point to branch
git checkout -b <newBranch> # create and switch

git switch <branch>         # switch to existing branch
git switch -c <newBranch>   # create and switch
git switch -                # return to previously checked out branch
```

```sh
git log <branch>            # show log for desired branch
git log --all               # show all of branchName
git log --oneline --decorate --graph --all
```
