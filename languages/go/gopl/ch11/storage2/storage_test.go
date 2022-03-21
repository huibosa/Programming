package storage

import "testing"

func TestCheckQuotaNotifiesUser(t *testing.T) {
	var notifiedUser, notifiedMsg string
	notifyUser = func(user, msg string) {
		notifiedUser, notifiedMsg = user, msg
	}

	const user = "joe@example.org"
	usage[user] = 980000000

	CheckQuota(user)
	if notifiedUser == "" && notifiedMsg == "" {
		t.Errorf("wrong user (%s) notified want %s", notifyUser, user)
	}
}
