from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
import numpy as np

# Flatten lattices for ML model
data = np.load('data/labeled_lattices.npz', allow_pickle=True)
print("Lattice shape: ", data['lattices'].shape)
print("Labels shape: ", data['labels'].shape)  

X = np.array([lattice.flatten() for lattice in data['lattices']])
y = data['labels']

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train a classifier
clf = RandomForestClassifier()
clf.fit(X_train, y_train)

# Evaluate
y_pred = clf.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred))
