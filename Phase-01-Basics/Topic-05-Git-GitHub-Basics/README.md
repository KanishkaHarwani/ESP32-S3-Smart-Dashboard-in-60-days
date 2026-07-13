# Topic 05 — Git & GitHub Basics

No firmware code in this one. Instead, you'll set up version control for the project you're about to build — a habit worth having from day one, not bolted on later once things get messy.

## Why this matters for embedded projects specifically

Firmware bugs are often caused by "wait, what did I change since it last worked?" Git gives you a clean answer to that question. It also means you can try something risky (a new sensor library, a rewrite of a driver) on a branch, without fear of breaking your only working version.

## The commands you actually need

You don't need to memorize all of Git — this repo only relies on a small, repeatable set:

```bash
git init                        # start tracking a project (once, at the start)
git status                      # what's changed since your last commit
git add <file>                  # stage a file for commit (or `git add .` for everything)
git commit -m "message"         # save a snapshot with a description
git log --oneline               # see your commit history
```

Once you have a GitHub repo connected:

```bash
git remote add origin <repo-url>   # connect to GitHub (once)
git push                           # send your commits to GitHub
git pull                           # bring down changes from GitHub
```

## Branches, briefly

A branch is a parallel line of work. Useful the moment you want to try something without touching your main, working code:

```bash
git checkout -b try-new-sensor   # create + switch to a new branch
# ... make changes, commit as normal ...
git checkout main                # back to your main branch
git merge try-new-sensor         # bring the changes in, once you're happy with them
```

For this repo, a simple habit works fine: one commit per topic/example you complete, on `main`. Save branches for when you're genuinely experimenting.

## A `.gitignore` for PlatformIO projects

PlatformIO generates build artifacts you don't want cluttering your repo. Create a `.gitignore` file with:

```
.pio/
.vscode/
*.o
*.bin
```

## A commit habit worth building now

Small, frequent commits with clear messages beat one giant commit at the end:

```bash
git add .
git commit -m "Topic 06: GPIO blink example working"
```

You'll thank yourself later when you need to find exactly when something broke.

## What's next

Topic 06 starts real hardware work again — GPIO, your first digital input and output on the ESP32-S3. Commit your Topic 04 blink example now if you haven't already; good time to start the habit.
