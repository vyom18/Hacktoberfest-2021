#install pytube first
#pip install pytube


import pytube  
from pytube import YouTube  
video_url = 'https://www.youtube.com/watch?v=yDsMZn3olFw'   
youtube = pytube.YouTube(video_url)  
video = youtube.streams.first()  
video.download('C:/Users/name/Desktop/')
