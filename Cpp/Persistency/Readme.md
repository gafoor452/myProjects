Breif : Function's data can be persisted in XML file.

Features:
1. To not loose the precision for float and double, base64 encoding/decoding is used.
2. Pugixml library(thirdyparty library) is used for xml processing.

How to use the XmlPersistency library?
1. Need to implement the Serializer and Deserializer for Function's data. This XmlPersistency utilize the serializer and deserializer to process the data.

About This Example:
1. SomeDataWithVectorOutput.hpp - holds the function data type which needs to be persisted.
2. SomeDataWithVectorXmlSerializer.* - Serailizer and Deserializer used by XmlPersistency and process the data.
