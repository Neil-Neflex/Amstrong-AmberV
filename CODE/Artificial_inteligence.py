import cv2
import serial
from inmoov import InMoov

# Initialisation du bras robotique
inmoov = InMoov()

# Initialisation de la caméra
cap = cv2.VideoCapture(0)

# Initialisation de la connexion série avec Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
    # Acquisition d'une image depuis la caméra
    ret, frame = cap.read()
    
    # Conversion de l'image en espace de couleurs HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Définition de la plage de couleurs rouges
    lower_red = np.array([0, 50, 50])
    upper_red = np.array([10, 255, 255])
    mask1 = cv2.inRange(hsv, lower_red, upper_red)

    lower_red = np.array([170, 50, 50])
    upper_red = np.array([180, 255, 255])
    mask2 = cv2.inRange(hsv, lower_red, upper_red)
    
    # Combinaison des masques pour détecter les couleurs rouges
    mask = mask1 + mask2
    
    # Détecter les contours des objets rouges
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Contrôle du bras robotique en fonction de la position des objets détectés
    for contour in contours:
        (x, y, w, h) = cv2.boundingRect(contour)
        x_center = x + w/2
        y_center = y + h/2
        
        # Convertir les coordonnées de l'image en angles de servo pour le bras robotique
        servo_angles = inmoov.map_pixel_to_servo(x_center, y_center)
        
        # Envoyer les angles de servo à Arduino
        for i, angle in enumerate(servo_angles):
            # Convertir l'angle en une valeur PWM pour le servo
            pwm_value = inmoov.map_servo_to_pwm(i, angle)
            
            # Envoyer la valeur PWM à Arduino
            ser.write(bytes([pwm_value]))
    
    # Afficher l'image
    cv2.imshow('frame', frame)
    
    # Sortir de la boucle si la touche 'q' est enfoncée
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libération des ressources
cap.release()
cv2.destroyAllWindows()
