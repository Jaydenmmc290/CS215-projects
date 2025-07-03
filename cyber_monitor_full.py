# Class: CS215
# Section: 001
# Author: Jayden McBride
# Purpose: This is a simple script that watches a folder for new or changed files.
#          If it finds a suspicious file type (like .exe or .bat), it gives a popup warning and logs it.

import os
import time
import subprocess
import sys

# Try to import watchdog. If it's not installed, install it first.
try:
    from watchdog.observers import Observer
    from watchdog.events import FileSystemEventHandler
except ImportError:
    print("Installing watchdog library...")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "watchdog"])
    from watchdog.observers import Observer
    from watchdog.events import FileSystemEventHandler

from tkinter import messagebox, Tk

# This is the folder it watches. Right now it’s set to the user’s home folder.
MONITOR_PATH = os.path.expanduser("~")
LOG_FILE = "alert_log.txt"

# These are the file types the script will alert about.
SUSPICIOUS_EXTENSIONS = [".exe", ".bat", ".js", ".vbs", ".cmd", ".scr", ".dll"]

# This function shows a popup window for alerts.
def show_alert(message):
    root = Tk()
    root.withdraw()
    messagebox.showwarning("Security Alert", message)
    root.destroy()

# This logs the activity to a text file so it can be checked later.
def log_activity(event_type, file_path):
    with open(LOG_FILE, "a") as log:
        log.write(f"[{time.ctime()}] {event_type.upper()}: {file_path}\n")

# This class handles the file events (like created or modified).
class MonitorHandler(FileSystemEventHandler):
    def process(self, event, event_type):
        file_path = event.src_path
        _, ext = os.path.splitext(file_path)
        if ext.lower() in SUSPICIOUS_EXTENSIONS and not event.is_directory:
            log_activity(event_type, file_path)
            show_alert(f"{event_type.capitalize()} suspicious file:\n{file_path}")

    def on_created(self, event):
        self.process(event, "created")

    def on_modified(self, event):
        self.process(event, "modified")

# This starts the program and begins watching the folder.
if __name__ == "__main__":
    print(f"Monitoring: {MONITOR_PATH}")
    print(f"Suspicious extensions: {', '.join(SUSPICIOUS_EXTENSIONS)}")

    event_handler = MonitorHandler()
    observer = Observer()
    observer.schedule(event_handler, path=MONITOR_PATH, recursive=True)
    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()