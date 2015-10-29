// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

'use strict';

var EventHub = require('../index.js');

var connectionString = 'Endpoint=sb://xxx;SharedAccessKeyName=yyy;SharedAccessKey=zzz';
var ehName = 'messages/events/';

var ehClient = new EventHub.Client(connectionString, ehName);
ehClient.GetPartitionIds().then(function(partitionIds) {
	console.log('PartCount=' + partitionIds.length);
	ehClient.CreateReceiver('$Default', '1').then(function(receiver) {
		
		/* start receiving */
		receiver.StartReceive(Date.Now).then(function() {
			receiver.on('error', function(error) {
				console.log(error.description);
				console.log('Receive error:' + error);
			});
			receiver.on('eventReceived', function(eventData) {
				console.log('Event received: ');
				console.log(eventData.Bytes);
				console.log(eventData.SystemProperties);
				console.log('');
			});
		});
	});
});
