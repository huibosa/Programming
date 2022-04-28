# ---
# jupyter:
#   jupytext:
#     formats: ipynb,py
#     text_representation:
#       extension: .py
#       format_name: light
#       format_version: '1.5'
#       jupytext_version: 1.12.0
#   kernelspec:
#     display_name: Python 3.9.2 64-bit
#     name: python3
# ---

import moviepy.editor as mp

clip = mp.VideoFileClip("./screeshot.mp4")
clip_resized = clip.resize(
    0.5
)  # make the height 360px ( According to moviePy documenation The width is then computed so that the width/height ratio is conserved.)
clip_resized.write_videofile("movie_resized.mp4")
